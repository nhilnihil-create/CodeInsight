#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int N;
    cin >> N;
    if(N==3) cout << "2 5 63" << endl;
    else if(N==4) cout << "2 5 20 63" << endl;
    else{
        cout << "2 3 4 9";
        N-=4;
        for(int i=8;i+2<30000 && N>=2;i+=6){
            cout << " " << i << " " << i+2;
            N-=2;
        }
        for(int i=15;i+6<30000 && N>=2;i+=12){
            cout << " " << i << " " << i+6;
            N-=2;
        }
        for(int i=6;N>0;i+=6){
            cout << " " << i;
            N--;
        }
        cout << endl;
    }
    
    return 0;
}