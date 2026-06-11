#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> l(n);
    int max = 0, index;
    for(int i = 0; i < n; i++){
        cin >> l[i];
        if(l[i] > max){
            max = l[i];
            index = i;
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(i == index) continue;
        sum += l[i];
    }

    if(max < sum) cout << "Yes" << endl;
    else cout << "No" << endl;
}