#include <bits/stdc++.h>
//#include <string.h>

using namespace std;

int main(){

    int n, counter = 0;

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j+=2){

            counter++;
        }
    }

    cout << counter << endl;

    return 0;

}

