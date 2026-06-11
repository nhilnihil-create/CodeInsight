#include <bits/stdc++.h>
using namespace std;


// 数字と、桁数を渡す
int same(int n,int d){
    vector<int> vec;
    int count = 0;

    for (int i=0; i<d; i++){
        vec.push_back(n%10);
        n = floor(n/10);
    }

    for (int i=0; i<vec.size(); i++){
        if(vec[0] == vec[i]) count++;
    }

    return count;
}

int main() {
    int n,abc,bcd,counta,countb;
    counta = 0;
    countb = 0;

    cin >> n;

    abc = floor(n / 10);
    bcd = n % 1000;

    abc = same(abc,3);
    bcd = same(bcd,3);

    if(max(abc,bcd) >= 3) cout << "Yes" << endl;
    else cout << "No" << endl;

}