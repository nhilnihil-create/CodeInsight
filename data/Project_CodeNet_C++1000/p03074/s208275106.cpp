#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N,K;
    cin >> N >> K;
    char S[N];
    vector<int> zero_list,one_list;
    int zero = 0, one = 0;
    char Sb = 'x';
    bool flg = false;
    if ( N == 1 ) {
        flg = true;
    }
    int ans = 0;
    if ( !flg ){
        REP(i,N) {
            cin >> S[i];
            if ( i == 0 ){
                if ( S[i] == '1' ) {
                    //zero_list.push_back(0);
                    ++one;
                    Sb = '1';
                } else {
                    one_list.push_back(0);
                    ++zero;
                    Sb = '0';
                }
            } else if ( i == N-1 ){
                if ( S[i] == '0' ) {
                    if ( Sb == '0' ){
                        ++zero;
                        zero_list.push_back(zero);
                        one_list.push_back(0);
                    } else {
                        one_list.push_back(one);
                        zero_list.push_back(1);
                        one_list.push_back(0);
                    }
                } else {
                    if ( Sb == '0' ){
                        zero_list.push_back(zero);
                        one_list.push_back(1);
                    } else {
                        ++one;
                        one_list.push_back(one);
                    }
                }
            } else {
                if ( S[i] == '0' ){
                    if ( Sb == '0' ) {
                        ++zero;
                    } else {
                        one_list.push_back(one);
                        one = 0;
                        zero = 1;
                    }
                    Sb = '0';
                } else {
                    if ( Sb == '1' ){
                        ++one;
                    } else {
                        zero_list.push_back(zero);
                        zero = 0;
                        one = 1;
                    }
                    Sb = '1';
                }
            }
            
        }
        
        /*for ( auto p : zero_list ){
            cout << p << " " ;
        }
        cout << endl;
        for ( auto p : one_list ){
            cout << p << " " ;
        }
        cout << endl;*/
        
        int s = zero_list.size();
        vector<int> oz,all;
        
        int num = 0;
        for ( int i = 0; i < s; ++i){
            oz.push_back(one_list[i]);
            num += one_list[i];
            all.push_back(num);
            oz.push_back(zero_list[i]);
            num += zero_list[i];
            all.push_back(num);
        }
        oz.push_back(one_list[s]);
        num += one_list[s];
        all.push_back(num);
        
        for ( int left = 0; left < oz.size(); left += 2 ){
            int p = oz.size() - 1, q = left + 2 * K;
            int right = min(p,q);
            
            int ans_sub = 0;
            if ( left == 0 ) ans_sub = all[right];
            else ans_sub = all[right] - all[left-1];
            
            chmax(ans,ans_sub);
            
        }
    }
    
    if ( flg ) cout << 1 << endl;
    else cout << ans << endl;
    
    
    
    
    
    
    
    
    return 0;
}
