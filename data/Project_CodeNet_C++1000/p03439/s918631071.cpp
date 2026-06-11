#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main(){
    ll n ; cin >> n;
    cout << 0 << endl;
    pair<ll,bool> left,right,center;
    string s; cin >> s;
    if(s.at(0)=='V'){ return 0;}
    else if(s.at(0)=='M'){left = make_pair(0,0),right = make_pair(n,0);}
    else if(s.at(0)=='F'){left = make_pair(0,1),right = make_pair(n,1);}
    while(true){
        center.first = (left.first+right.first)/2;
        cout << center.first << endl;
        cin >> s;
        char sex = s.at(0);
        if(sex=='V'){
            return 0;
        }else{
            center.second = (sex=='F');
            if(left.first%2 == center.first%2){
                if(left.second==center.second){
                    left = center;
                }else{
                    right = center;
                }                
            }else{
                if(left.second==center.second){
                    right = center;
                }else{
                    left = center;
                }                
            }            
        }
    }
    return 0;
}