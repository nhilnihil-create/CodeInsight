#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N,count = 1;
    cin >> N;
    vector<int> d(N);
    for (int i = 0; i < N; i++)
    {
        cin >> d.at(i);
    }
    sort(d.begin(),d.end());
    for (int i = 1; i < N; i++)
    {
        int k = d.at(i) - d.at(i-1);
        if(k > 0){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}