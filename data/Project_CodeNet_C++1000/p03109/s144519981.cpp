#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string s;
    cin >> s;
    string s2;
    s2=s.substr(5,2);
    int a;
    a=atoi(s2.c_str());
    if(a>=5){
        cout << "TBD" << endl;
    }
    else{
        cout << "Heisei" << endl;
    }

    

    return 0;
}