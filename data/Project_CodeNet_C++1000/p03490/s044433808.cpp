    #include <iostream>
    #include <cstdio>
    #include <bitset>
    #define M 8005
    using namespace std;
     
    int x, y, z, c;
    string s;
    bitset<M * 2> bs[2];
    int main() {
    	int i;
    	cin >> s >> x >> y;
    	for (i = 0; s[i] == 'F'; i++);
    	bs[0][i + M] = bs[1][M] = 1;
    	for (; i <= s.size(); i++) {
    		if (s[i] == 'F') c++;
    		else bs[z] = (bs[z] << c) | (bs[z] >> c), z = !z, c = 0;
    	}
    	cout << (bs[0][x + M] & bs[1][y + M] ? "Yes" : "No");
    	return 0;
    }