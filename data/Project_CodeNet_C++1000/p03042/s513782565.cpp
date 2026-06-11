#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k = n % 100;
    int s = n / 100;
    if((s > 12 || s == 0)&& k <= 12 && 0 < k){
        cout << "YYMM" << endl;
    }else if(0 < s && s <= 12 && (k == 0 || 12 < k)){
        cout << "MMYY" << endl;
    }else if(0 < s && s <= 12 && 0 < k && k <= 12){
        cout << "AMBIGUOUS" << endl;
    }else{
        cout << "NA" << endl;
    }

}