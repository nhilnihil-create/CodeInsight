#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
long long maxv = 1e9;

int main()
{
    int N;
    cin>>N;
    int A;
    int maxi=INT_MIN;
    int total=0;
    for(int i=0;i<N;i++){
        cin>>A;
        total+=A;
        if(A>maxi){
            maxi=A;
        }
    }
    if(total-maxi>maxi){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}