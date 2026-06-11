#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long a=0,b=0;
    string n;
    cin>>n;
    f(i,0,n.size()){
        if(n[i]=='0'){
            a++;
        }
        else{
            b++;
        }
    }
    cout<<min(a,b)*2<<endl;
    return 0;
}
