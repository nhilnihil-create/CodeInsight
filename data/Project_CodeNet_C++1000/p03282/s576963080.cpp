#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    string s;
    long long k,c=0,ans=0;
    cin>>s>>k;
    f(i,0,s.size()){
        if(s[i]=='1'){
            c++;
        }
        else{
            ans=i;
            break;
        }
    }
    if(c>=k){
        cout<<'1'<<endl;
    }
    else{
        cout<<s[ans]<<endl;
    }
    return 0;
}
