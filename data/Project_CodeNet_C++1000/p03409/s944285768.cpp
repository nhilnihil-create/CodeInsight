#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct{int x,y;}point;
int main(){
    int n,x,y,del=-1,max_y=-1,ans=0;
    cin>>n;
    vector<point>a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y;
    sort(a.begin(),a.end(),[](const point& a,const point& b){return a.x!=b.x?a.x<b.x:a.y<b.y;});
    for(int i=0;i<n;i++)cin>>b[i].x>>b[i].y;
    sort(b.begin(),b.end(),[](const point& a,const point& b){return a.x!=b.x?a.x<b.x:a.y<b.y;});
    for(int i=0;i<n;del=max_y=-1,i++){
        for(int j=0;j<a.size();j++)if(a[j].x<b[i].x&&a[j].y<b[i].y&&max_y<a[j].y)max_y=a[j].y,del=j;
        if(del>=0){a.erase(a.begin()+del);ans++;}
    }
    cout<<ans<<endl;
    return 0;
}