#include <bits/stdc++.h>
using namespace std;

int main(){
    int l;
    cin >> l;

    int num_ver = 0;

    for (auto i = 0; i < 21; i++)
    {
        if(pow(2,i) > l){
            num_ver = i ;
            break;
        }
    }

    int num_edge = (num_ver-1)*2;
    vector<int> edge(num_ver, -1);

    for (auto i = num_ver-1; i >= 0; i--)
    {
        if(l-pow(2, i) >= pow(2, num_ver-1)){
            edge[i] = l - pow(2, i);
            l -= pow(2, i);
        }
    }

    for (auto i = 0; i < edge.size(); i++)
    {
        if(edge[i] != -1){
            num_edge += 1;
        }
    }

    cout << num_ver << " " << num_edge << endl;
    for (auto i = 1; i < num_ver; i++)
    {
        cout << i << " " <<  i + 1 << " " << " " << 0 << endl;
        cout << i << " " <<  i + 1 << " " << " " << pow(2, i-1) << endl;
    }
    for (auto i = 0; i < edge.size(); i++)
    {
        if(edge[i] != -1){
            cout << i + 1 << " " << num_ver << " " << edge[i] << endl;
        }
    }
}