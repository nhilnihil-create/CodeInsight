#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    vector<int> v(5);
    int k;

    for(int i=0;i<5;i++){
        cin >> v[i];
    }

    cin >> k ;

    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if(v[j]-v[i]>k){
                cout<<":("<<endl;
                return 0;
            }
        }
    }

    cout<<"Yay!"<<endl;

    return 0;
}