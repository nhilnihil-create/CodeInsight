#include <bits/stdc++.h>
using namespace std;

int main(){
    int L;
    cin >> L;
    L--;
    int L1=L;
    int digit=0;
    int cnt =0; //0以外に貼る辺の本数
    while(L1>0){
        if(L1%2==0){
            cnt +=2;
            L1 = (L1-2)/2;
            digit++; continue;
        }
        else{
            cnt++;
            L1 = (L1-1)/2;
            digit++;
        }
    }

    int N=digit+1;
    cout << N << " " << cnt +N-1 << " " << endl;

    //1,....,Nを使う
    for(int i=0; i<N-1;i++){
        cout << i+1<< " " << i+2 << " " << 0 <<endl;
    }
    while(L>0){
        if(L%2==1){
            cout << N-1 << " "  << N << " " << (L+1)/2 << endl;
            L = (L-1)/2; N--; continue;
        }
            cout << 1 << " " << N << " " << L << endl;
            cout << N-1 << " " << N << " " << L/2 << endl;
            L = L/2-1; N--;
    }
}