#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

char fi[100][100];

int main(){
    int a,b; cin >> a >> b;
    cout << 100 << " " << 100 << endl;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(i<50)fi[i][j]='#';
            else fi[i][j]='.';
        }
    }
    a--; b--;
    for(int i=0;i<50;i++){
        for(int j=0;j<100;j++){
            if(a==0)break;
            if(i%2==0&&j%2==0){
                fi[i][j]='.';
                a--;
            }
        }
        if(a==0)break;
    }
    for(int i=51;i<100;i++){
        for(int j=0;j<100;j++){
            if(b==0)break;
            if(i%2==0&&j%2==0){
                fi[i][j]='#';
                b--;
            }
        }
        if(b==0)break;
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            cout << fi[i][j];
        }
        cout << endl;
    }
}