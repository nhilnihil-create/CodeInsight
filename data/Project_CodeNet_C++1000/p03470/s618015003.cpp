#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> d(N);
    for(int i = 0; i < N ; i++){
        cin >> d.at(i);
    }
    sort(d.begin() , d.end());
    reverse(d.begin(), d.end());

    int count = 0;
    int max = 101;
    for(int n : d){
        if(n < max){
            count++;
            max = n;
        }
    }

    cout << count << endl;

}