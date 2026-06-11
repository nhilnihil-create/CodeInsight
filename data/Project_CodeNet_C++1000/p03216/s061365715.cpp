#include<bits/stdc++.h>
using namespace std;

long long solve(string s, long long k){
    long long n = (long long)s.size();

    long long d = 0;
    long long m = 0;
    long long dm = 0;
    long long dmc = 0;
    long long l = 0;
    for(long long r = 0; r < n; r++){

        if(r - l == k){
            if(s[l] == 'D'){
                d--;
                dm -= m;
            }else if(s[l] == 'M'){
                m--;
            }

            l++;
        }

        if(s[r] == 'D'){
            d++;
        }else if(s[r] == 'M'){
            dm += d;
            m++;
        }else if(s[r] == 'C'){
            dmc += dm;
        }

        

        
    }


    return dmc;
}

int main(){
    long long n; cin >> n;
    string s; cin >> s;
    long long q; cin >> q;
    for(long long i = 0; i < q; i++){
        long long k; cin >> k;

        cout << solve(s, k) << endl;
    }
    return 0;
}