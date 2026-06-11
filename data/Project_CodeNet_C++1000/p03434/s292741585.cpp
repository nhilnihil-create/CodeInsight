#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    vector<int> vec(N);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end()); 
    reverse(vec.begin(), vec.end());

    int suma = 0;
    int sumb = 0;

    for(int i = 0; i < N; i++){
        if(i%2 == 0){
            suma += vec[i];
        }
        else{
            sumb += vec[i];
        }

    }

    cout << suma-sumb << endl;
}
