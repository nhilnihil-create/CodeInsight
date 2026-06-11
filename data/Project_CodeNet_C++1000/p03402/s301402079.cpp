#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int A,B;
    cin >> A >> B;A --;B --;
    bool b[50][100],w[50][100];
    fill(b[0],b[50],false);
    fill(w[0],w[50],false);
    for(int j = 0;j < 50;j += 2){
        for(int i = 0;i < 100;i += 2){
            if(A==0&&B==0) break;
            if(B>0){b[j][i]=true;B --;}
            if(A>0){w[j+1][i]=true;A --;} 
        }
        if(A==0&&B==0) break;
    }
    cout << 100 << " " << 100 << endl;
    for(int j = 0;j < 50;j ++){
        for(int i = 0;i < 100;i ++){
            if(b[j][i]) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
    for(int j = 0;j < 50;j ++){
        for(int i = 0;i < 100;i ++){
            if(w[j][i]) cout << '.';
            else cout << '#';
        }
        cout << endl;
    }
    return 0;
}