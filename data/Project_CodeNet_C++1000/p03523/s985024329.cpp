#include <bits/stdc++.h>
#include <stdio.h>
#include <cmath>
using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)

typedef long long ll;

const ll inf = 1e18+7;
const ll mod = 1e9+7;


int main() {
    string s;
    cin>>s;

    string A="AKIHABARA",B="KIHABARA",C="AKIHBARA",
            D="AKIHABRA",E="AKIHABAR",F="AKIHABR",
             G="AKIHBAR",H="KIHABAR",I="AKIHBRA",
              J="KIHABRA",K="KIHBARA",L="AKIHBR",
               M="KIHABR",N="KIHBAR",O="KIHBRA",P="KIHBR";

    if(s==A||s==B||s==C||s==D||s==E||s==F||s==G||s==H||
            s==I||s==J||s==K||s==L||s==M||s==N||s==O||s==P){
            cout<<"YES"<<endl;
            return 0;
    }

    cout<<"NO"<<endl;

}
