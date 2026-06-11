#include<bits/stdc++.h>
using namespace std;
long gcd(long a,long b){
    if(a < b)swap(a,b);
    if(a%b == 0)return b;
    else return gcd(b,a%b);
}

long lcm(long a,long b){
    return a*b/gcd(a,b);
}

int main(){
    long n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    long lcmm = lcm(n,m);
    long gcdd = gcd(n,m);
    bool chk = true;
    long a = lcmm/n;
    long b = lcmm/m;
    
    for(int i=0;i<gcdd;i++){
        if(s[i*b] != t[i*a])chk = false;
    }

    if(!chk)lcmm = -1;
    cout << lcmm << endl;
    
}
