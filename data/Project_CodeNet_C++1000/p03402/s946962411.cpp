#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

char tbl[100][100];
int main(){
    long a,b;
    cin >> a >> b;

    for(int i=0; i<50; i++){
        for(int j=0; j<100; j++){
            tbl[i][j] = '.';
            tbl[50+i][j] = '#';
        }
    }

    int count=1;
    for(int i=0; i<50; i+=2){
        if(count>=b) break;
        for(int j=0; j<100; j+=2){
            if( count>=b) break;
            tbl[i][j]='#';
            count++;
        }
    }
    count=1;
    for(int i=51; i<100; i+=2){
        if(count>=a) break;
        for(int j=0; j<100; j+=2){
            if( count>=a) break;
            tbl[i][j]='.';
            count++;
        }
    }

    cout << 100 << " " << 100 << endl;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            cout << tbl[i][j];
        }
        cout << endl;
    }
    return 0;
}