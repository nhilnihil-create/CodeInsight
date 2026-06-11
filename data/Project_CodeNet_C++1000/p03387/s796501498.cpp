#include <bits/stdc++.h>
using namespace std;

int main(){

    int a, b, c;
    cin >> a >> b >> c;

    int cnt = 0;
    while((a!=b) || (b!=c) || (c!=a)){
        if(a==b){
            if(a<c){
                a++;
                b++;
            }
            else c += 2;
        }
        else if(b==c){
            if(b<a){
                b++;
                c++;
            }
            else a += 2;
        }
        else if(c==a){
            if(c<b){
                c++;
                a++;
            }
            else b += 2;
        }
        else{
            int temp;
            temp = min(a, min(b, c));
            if(temp == a) a = temp+2;
            if(temp == b) b = temp+2;
            if(temp == c) c = temp+2;
        }
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}