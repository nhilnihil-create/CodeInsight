#include <bits/stdc++.h>
#include <climits>
using namespace std;

//bool comp(pair<int,int> a, pair<int,int> b){return a.second < b.second;}

int main(void){
    
    long long X,Y;
    cin >> X >> Y;
    
    long long Z = X;
    int cont = 0;
    while(Z <= Y){

        Z *= 2;
        cont++;

    }
    cout << cont << endl;    
}
