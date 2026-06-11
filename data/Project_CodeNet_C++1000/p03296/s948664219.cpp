#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> slimes(n);for(int i=0;i<n;i++){cin >> slimes[i];}

    int acc = 0;
    int judge = -2;
    for (int i=0;i<n-1;i++){
        if (i == judge + 1){
            judge = -2;
            continue;
        }
        if (slimes[i] == slimes[i+1]){
            acc++;
            judge = i;
        }
    }
    cout << acc << endl;
    return 0;

}