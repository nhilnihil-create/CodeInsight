#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int N;
    cin>>N;
    int count=0;
    while(N>=3){
        count++;
        N-=3;
        if(N-3>=3)continue;
        else{
            count++;
            break;
        }
    }
    cout<<count<<endl;
}