#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    cin >> a.at(i);

    sort(a.rbegin(),a.rend());

    int A=0,B=0;    
    int flg = 0;

    for(auto p:a){
        if(flg == 0){
            A += p;
            flg = 1;
        }else{
            B += p;
            flg =0;
        }
    }

    cout << A-B << endl;

}