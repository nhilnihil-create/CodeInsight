#include <iostream>

int main() {
    using namespace std;
    int N;
    cin >> N;
    if(N<=4){
        cout << "2 3 25";
        if(N==4){
            cout << " 30";
        }
        cout << endl;
        return 0;
    }
    if(N<15000){
        if(N%2==1){
            cout << "6 ";
            N--;
        }
        cout << "2 4 3 9 ";
        N-=4;
        if(N==0){
            cout << endl;
            return 0;
        }
        for(int i=7;i<=30000;i++){
            if(i%2==0&&i%6!=0){
                cout << i << " ";
                N--;
            }
            if(N==0){
                cout << endl;
                return 0;
            }
        }
        for(int i=13;i<=30000;i++){
            if(i%3==0&&i%6!=0){
                cout << i << " ";
                N--;
            }
            if(N==0){
                cout << endl;
                return 0;
            }
        }
    }
    if(N>=15000){
        N-=15000;
        for(int i=1;i<=30000;i++){
            if(i%6==2||i%6==3||i%6==4){
                cout << i << " ";
            }
            if(i%6==0&&N>=i/6){
                cout << i << " ";
            }
        }
        cout << endl;
    }
}