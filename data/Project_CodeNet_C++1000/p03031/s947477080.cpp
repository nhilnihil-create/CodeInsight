#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void){
    // Your code here!
 int n,m;
 cin>>n>>m;
 
 vector<vector<int>> vec(m);
 vector<int> p(m,0);
 int a,b;
 for(int i=0;i<m;i++){
     
     cin>>a;
     for(int j=0;j<a;++j){
         cin>>b;
         b--;
         vec[i].push_back(b);
     }
 }
 for(int i=0;i<m;i++){
     cin>>p[i];
 }
 
int count=0,ans=0;
for(int i=0;i<(1<<n);++i){
    count=0;
    for(int j=0;j<m;j++){
            int count1=0;
        for(int k=0;k<vec[j].size();k++){
           if((1<<vec[j][k]) & i)
                count1++;
        }
        {
                if(count1%2==p[j]){
                    count++;
                }
                    
        }
    }
    if(count==m)
    ans++;
}

cout<<ans;

}
