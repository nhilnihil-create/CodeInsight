#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a;
    long long int ans=0;
    long long int count=0;
    for(int i=0; i<n; i++){
        cin >> a;
        if(a%2==0) count++;
    }
    ans=pow(3,n)-pow(2,count);
    cout << ans << endl;
}