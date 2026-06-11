#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,Y;
    cin >> N >> Y;
    
    int res10000 = -1;
    int res5000 = -1;
    int res1000 = -1;

    for(int a=0; a<=N; a++){
        for(int b=0; b<=N-a; b++){
            int c = N - a - b;
            if(a*10000 + b*5000 + c*1000 == Y){
                res10000 = a;
                res5000 = b;
                res1000 = c;
                break;
            }
        }
    }

    cout << res10000 << " " << res5000 << " " << res1000 << endl;
}