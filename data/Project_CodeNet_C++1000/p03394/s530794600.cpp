#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    int q=N/8; int r=N%8;

    if(q==0&&r==3){
        cout << 2 << " " << 5 << " " << 63 << endl; return 0;
    }

    for(int i=0; i<q; i++){
        cout << 12*i+2 << " " << 12*i+3 << " " << 12*i+4 << " " << 12*i+6 << " ";
        cout << 12*i+8 << " " << 12*i+9 << " " << 12*i+10 << " " << 12*i+12 << " ";
    }

    if(r==0){
        cout << endl;
    }
    if(r==1){
        cout << 12*q+12 << endl;
    }
    if(r==2){
        cout << 12*q+6 << " " << 12*q+12 << endl;
    }
    if(r==3){
        cout << 12*q+4 << " " << 12*q+8 << " " << 12*q+12 << endl;
    }
    if(r==4){
        cout << 12*q+2 << " ";
        cout << 12*q+3 << " ";
        cout << 12*q+9 << " ";
        cout << 12*q+10 << endl;
    }
    if(r==5){
        cout << 12*q+2 << " ";
        cout << 12*q+3 << " ";
        cout << 12*q+6 << " ";
        cout << 12*q+9 << " ";
        cout << 12*q+10 << endl;
    }
    if(r==6){
        cout << 12*q+2 << " ";
        cout << 12*q+3 << " ";
        cout << 12*q+4 << " ";
        cout << 12*q+8 << " ";
        cout << 12*q+9 << " ";
        cout << 12*q+10 << endl;
    }
    if(r==7){
        cout << 12*q+2 << " ";
        cout << 12*q+3 << " ";
        cout << 12*q+4 << " ";
        cout << 12*q+6 << " ";
        cout << 12*q+8 << " ";
        cout << 12*q+9 << " ";
        cout << 12*q+10 << endl;
    }
}