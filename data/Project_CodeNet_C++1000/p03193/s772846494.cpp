#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int main(void){
    ll N , H , W ;
    cin >> N >> H >> W ;
    ll A[N] , B[N] ;
    for(ll i = 0 ; i < N ; i++){
        cin >> A[i] >> B[i] ;
    }
    ll cnt = 0 ;
    for(ll i = 0 ; i < N ; i++){
        if(H <= A[i] && W <= B[i]){
            cnt++ ;
        }
    }
    cout << cnt << endl;
}