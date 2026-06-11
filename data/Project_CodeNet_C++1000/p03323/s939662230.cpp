/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

int diff(int a, int b){
    return max(a,b)-min(a,b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
    cin>>a>>b;
    if(diff(a,b)<2) cout<<"Yay!\n";
    else cout<<":(\n";
	return 0;
}
