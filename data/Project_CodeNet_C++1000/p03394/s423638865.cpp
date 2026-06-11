#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

long long gcd(long long N, long long M){
    while (true){
        if (min(N,M)==0){
            return max(N,M);
        }else if (N>M){
            N%=M;
        }else{
            M%=N;
        }
    }
}

int main(){
    int N;
    cin >> N;

    if(N==3){
        cout << "2 5 63" << endl;
        return 0;
    }

    int sum_=0;
    int cnt=0;

    for(int i=1; i<=30000; i++){
        if(cnt<N-1 && (i%2==0 || i%3==0)){
            sum_+=i;
            cout << i << ' ';
            cnt++;
            continue;
        }
        if(cnt==N-1){
            if((i+sum_)%6==0 && gcd((long long) sum_, (long long)i)!=1){
                cout << i << ' ' << endl;
                return 0;
            }
        }
    }

    for(int i=1; i<=30000; i++){
        if(!(i%2==0 || i%3==0)){
            if((i+sum_)%6==0 && gcd((long long) sum_, (long long)i)!=1){
                cout << i << ' ' << endl;
                return 0;
            }
        }
    }
    //cout << max_ << endl;
    return 1;
}