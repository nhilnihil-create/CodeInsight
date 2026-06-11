#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;

int main(void){

    string a,b;

    cin >> a >> b;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    reverse(b.begin(),b.end());

    if(a < b) 
    cout << "Yes" <<endl;

    else
    cout << "No" <<endl;
    

    return 0;
}