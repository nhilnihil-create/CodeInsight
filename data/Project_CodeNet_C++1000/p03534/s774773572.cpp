#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int len, a[3];
    string s;
    cin >> s;
    len = s.length();
    fill(a, a+3, 0);
    for(int i=0;i<len;i++){
        a[s[i] - 'a']++;
    }
    sort(a, a+3);
    if(a[2] - a[0] < 2){
        puts("YES");
    }else{
        puts("NO");
    }
	return 0;
}