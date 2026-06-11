#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i =0 ;i <n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    //for(int i = 0; i < n;i++)cout << "a[" << i <<"] = " <<a[i] << endl;
    int sum = 0;
    for(int i = 0; i < n;){
        int x = upper_bound(a.begin(),a.end(),a[i]) - a.begin();
        if (a[i] < x - i)
            sum += (x - i) - a[i];
        else if (x - i < a[i])
            sum += x - i;
        //cout << "a[" << i <<"] = " <<a[i] << ", " << x << endl;

        i = x;
    }
    cout << sum << endl;
}

