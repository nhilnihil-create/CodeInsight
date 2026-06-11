#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
    /*
    {
       Md: Saroar Zahan Sojib
       Green University of Bangladesh
       https://web.facebook.com/sojib.bdb
    }
   */
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> vec;
    for (int i=0; i<=25; i++)
        for (int j=0; j<=14; j++)
            vec.push_back(4*i+7*j);
    vector<int>::iterator ik = find(vec.begin(), vec.end(), n);
    if (ik != vec.end())
	    cout <<"Yes"<<endl;
    else
	    cout << "No"<<endl;

    return 0;
}
