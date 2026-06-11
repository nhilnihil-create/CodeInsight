#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
using ull = unsigned long long;
const static int MOD = 1000000007;

int main(){
    string S;
    cin >> S;
    ull sz = S.size(), power[sz+1], undecided_left[sz+1], a[sz+1], c = 0, answer = 0;
    power[0] = 1;
    for (unsigned i = 0; i < sz; i++){
        power[i+1] = power[i]*3 %MOD;
    }
    undecided_left[0] = a[0] = 0;
    for (unsigned i = 0; i < sz; i++){
        undecided_left[i+1] = undecided_left[i];
        a[i+1] = a[i];
        if(S[i] == '?') undecided_left[i+1]++;
        else if(S[i] == 'A') a[i+1]++;
    }
    for (int i = sz-1; i >= 0; i--){
        if(S[i] == 'C') c++;
        else if(S[i] == 'B' || S[i] == '?'){
            answer = (answer + a[i]*c*power[undecided_left[sz] - (ull)(S[i] == '?')]) %MOD;
            if(undecided_left[sz] > undecided_left[i+1]) answer = (answer + a[i]*(undecided_left[sz] - undecided_left[i+1])*power[undecided_left[sz] - (ull)(S[i] == '?') - 1]) %MOD;
            if(undecided_left[i]) answer = (answer + undecided_left[i]*c*power[undecided_left[sz] - (ull)(S[i] == '?') - 1]) %MOD;
            if(undecided_left[sz] > undecided_left[i+1] && undecided_left[i]) answer = (answer + undecided_left[i]*(undecided_left[sz] - undecided_left[i+1])*power[undecided_left[sz] - (ull)(S[i] == '?') - 2]) %MOD;
        }
    }
    printf("%llu\n", answer);
	return 0;
}