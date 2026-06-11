#include <bits/stdc++.h>
using namespace std;


int main() {

    int64_t a,b;
    cin>>a>>b;

    //1/2*n*(n+1) 1/2*n*(n+1)+(n+1)
    //b-a=n+1
    //n=b-a-1
    //1/2*n*(n+1)-a

    int64_t n=b-a-1;
    cout<<n*(n+1)/2-a<<endl;

	return 0;
}