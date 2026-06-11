#include <iostream>

using namespace std;
int main(void){
    int N;
    cin >> N;
    int sum = 0;
    int max_S = 0;
    for(int i=0;i<N;i++){
        int l;
        cin >> l;
        sum += l;
        max_S = max(max_S,l);
    }
    string ans = "Yes";
    if(max_S >= sum - max_S){
        ans = "No";
    }
    cout << ans << endl;
}
