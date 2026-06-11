#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int , int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 


int main (){
    string s ;
    cin >> s; 
    int n = s.size() ;
    int ans = 0 ;
    for(int i = 0; i < n;){
        int num = 0;
        for(int j = i; j < n; j++){
            if(s[j] != 'A' && s[j] != 'C' && s[j] != 'G' && s[j] != 'T'){
                break ;
            }
            else {
                num++ ;
            }
        }
        ans = max(ans, num) ;
        i +=  num + 1;
    }
    cout << ans << endl ;
}
