#include <bits/stdc++.h>
#define pb push_back
#define Int int64_t
using namespace std;

int N,M,A,B,C,K;
int main()
{
    cin>>N;
    vector<Int> A(N);
    for(auto &x:A) cin>>x;
    int largest=*max_element(A.begin(),A.end());
    Int sum=accumulate(A.begin(),A.end(),0);
    sum-=largest;
    cout<<(largest<sum ? "Yes\n":"No\n");
}