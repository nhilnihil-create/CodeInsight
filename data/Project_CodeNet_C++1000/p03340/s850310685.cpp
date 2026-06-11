#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <map>
#include <iomanip>
#include <limits.h>
#include <bitset>

using namespace std;    
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const bool DEBUG = true;

bool check( vector<int> &cnt ){
    for(int i = 0; i < cnt.size(); i++){
        if(cnt[i] > 1) return false;
    }
    return true;
}

void add( vector<int> &cnt, bitset<20> &bs ){
    for(int i = 0; i < 20; i++){
        cnt[i] += bs[i];
    } 
}

void sub( vector<int> &cnt, bitset<20> &bs ){
    for(int i = 0; i < 20; i++){
        cnt[i] -= bs[i];
    } 
}


int main(){

    int n;
    cin >> n;

    vector < bitset<20> > v(n);
    for(int i = 0; i < n; i++){
        unsigned long s;
        cin >> s;
        bitset<20> bs(s);
        v[i] = bs;
    }

    vector<int> cnt(20);

    int left = 0;
    int right = -1;
    ll ans = 0;

    while(true){

        if( check(cnt) && right < n ){
            right ++;
            //ans += (right - left);
            if(right != n) add( cnt, v[right] );
        }
        else{
            ans += (right - left);
            sub( cnt, v[left] );
            left ++;
        }

        if(right == n && left == n) break;

    }
    
    cout << ans  << endl;


}