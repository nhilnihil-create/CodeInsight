#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, N, M ,K;
    int count = 0;
    string a, b, c;
    cin >> N >> a >> b >> c;

    for(int i = 0; i < N; i++){
        if(a.at(i)==b.at(i) && b.at(i)==c.at(i)) continue;
        else if(a.at(i)==b.at(i) && b.at(i)!=c.at(i)) count++;
        else if(b.at(i)==c.at(i) && c.at(i)!=a.at(i)) count++;
        else if(c.at(i)==a.at(i) && a.at(i)!=b.at(i)) count++;
        else count += 2;
    }

    cout << count << endl;
}