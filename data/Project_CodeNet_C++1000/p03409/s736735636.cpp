#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>red(n);
    vector<pair<int,int>>blue(n);
    int a[n],b[n],c[n],d[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        red[i]={a[i],b[i]};
    }
    for(int i=0;i<n;i++){
        cin>>c[i]>>d[i];
        blue[i]={d[i],c[i]};
    }
    sort(red.begin(),red.end(),greater<pair<int,int>>());//赤:x座標降順
    sort(blue.begin(),blue.end());//青:y座標昇順
    int x=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<blue.size();j++){
            if(red[i].first<blue[j].second && red[i].second<blue[j].first){
                blue.erase(blue.begin()+j);
                x++;
                break;
            }
        }
    }
    cout<<x<<endl;
    return 0;
}