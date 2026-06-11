/* In the name of Allah */
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define debug cout << "here!"
#define pii pair<int , int>
#define pdd pair<double , double>
#define F first
#define S second
const int maxn = 1e5 * 5 + 10 , inf = 1e9 , pi = 3.14159265;
bool check(int x){
    for (int i = 2; i <= sqrt(x); i ++){
        if (x % i == 0){
            int j = 2;
            while (pow(i , j) < x){
            //    cout << i << " " << endl;
                j ++;
            }
            if (pow(i , j) == x){
                return 1;
            }
        }
      //  cout << "salam" << endl;
    }
    return 0;
}
void solve(){
    
}
void in(){
    int x; cin >> x; int ans = 1;
    for (int i = 1; i <= x; i ++){
        if (check(i) == 1){
            ans = i;
        }
        //cout << ans << endl;
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    in();
    return 0;
}
