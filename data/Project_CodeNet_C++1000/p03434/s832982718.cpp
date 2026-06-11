#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int str = 0;
    int Acount = 0;
    int Bcount = 0;
    for(int i=0;i<N;i++){
        str = a.at(i);
        if(i%2 == 0){
            Acount += str;
        }
        else{
            Bcount += str;
        }
    }

    cout << Acount - Bcount << endl;
}