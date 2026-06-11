#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long double sum=0;
    for(int i=0;i<n;i++){
        string s;
        long double x,S;
        cin >> x>>s;
        if(s=="JPY"){
            sum+=x;
        }
        else{
            S=380000*x;
            sum+=S;
        }
    }
    cout << sum << endl;
    return 0;
}