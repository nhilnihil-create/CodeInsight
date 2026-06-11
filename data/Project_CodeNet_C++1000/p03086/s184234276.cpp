#include <bits/stdc++.h>
using namespace std;

int main(){
    string N;
    cin >> N;
    int count=0,cmax=0;
    N+="0";
    for(int i:N){
        if(!('A'==i||'G'==i||'C'==i||'T'==i)){
            cmax=max(cmax, count);
            count=0;
            continue;
        }
        count++;
    }
    cout << cmax << endl;
}
