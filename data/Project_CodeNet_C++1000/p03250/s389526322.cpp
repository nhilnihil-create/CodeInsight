#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int A,B,C;
    cin >> A >> B >> C;
    vector<int> v {A,B,C};
    sort(v.begin(),v.end());
    string one = to_string(v[2]);
    string two = to_string(v[1]);
    int three = v[0];
    string onetwo = one + two;
    cout << stoi(onetwo) + three;

}