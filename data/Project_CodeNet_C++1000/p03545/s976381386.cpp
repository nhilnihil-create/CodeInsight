#include <bits/stdc++.h>
using namespace std;

int main() {
    string ABCD;
    cin >> ABCD;
    int A = ABCD[0] - '0';
    int B = ABCD[1] - '0';
    int C = ABCD[2] - '0';
    int D = ABCD[3] - '0';
    if(A+B+C+D==7) {
        //cout<<"A+B+C+D=7"<<endl;
        cout<<A<<"+"<<B<<"+"<<C<<"+"<<D<<"=7"<<endl;
    }else if(A-B+C+D==7) {
        //cout << "A-B+C+D=7"<<endl;
        cout<<A<<"-"<<B<<"+"<<C<<"+"<<D<<"=7"<<endl;
    }else if(A+B-C+D==7) {
        //cout <<"A+B-C+D=7"<<endl;
        cout<<A<<"+"<<B<<"-"<<C<<"+"<<D<<"=7"<<endl;
    }else if(A-B-C+D==7) {
        //cout <<"A-B-C+D=7"<<endl;
        cout<<A<<"-"<<B<<"-"<<C<<"+"<<D<<"=7"<<endl;
    }else if(A+B+C-D==7) {
        //cout <<"A+B+C-D=7"<<endl;
        cout<<A<<"+"<<B<<"+"<<C<<"-"<<D<<"=7"<<endl;
    }else if(A-B+C-D==7) {
        //cout <<"A-B+C-D=7"<<endl;
        cout<<A<<"-"<<B<<"+"<<C<<"-"<<D<<"=7"<<endl;
    }else if(A+B-C-D==7) {
        //cout <<"A+B-C-D=7"<<endl;
        cout<<A<<"+"<<B<<"-"<<C<<"-"<<D<<"=7"<<endl;
    }else if(A-B-C-D==7) {
        //cout <<"A-B-C-D=7"<<endl;
        cout<<A<<"-"<<B<<"-"<<C<<"-"<<D<<"=7"<<endl;
    }
}