#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
	string s;
	cin >> s;
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a') a++;
        else if(s[i] == 'b') b++;
        else c++;
    }
    int mi = min({a, b, c});
    int ma = max({a, b, c});
    cout << ((ma - mi <= 1)? "YES" : "NO") << endl;
	return 0;
}