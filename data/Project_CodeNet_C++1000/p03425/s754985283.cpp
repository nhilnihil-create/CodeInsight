#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<set> 
#include<map>
long long combi(long long a) {

    return a*(a-1)*(a-2) / 6;
}

int main() {
   int n; std::cin >> n;
   std::vector<std::string> s(n);
   std::map<char, long long> t;

   long long ans = 0;
   long long sum = 0;
   t.insert(std::make_pair('M', 0));
   t.insert(std::make_pair('A', 0));
   t.insert(std::make_pair('R', 0));
   t.insert(std::make_pair('C', 0));
   t.insert(std::make_pair('H', 0));
   for(int i = 0; i < n; i++) {
       std::cin >> s[i];
       if (s[i][0] == 'M' || s[i][0] == 'A' || s[i][0] == 'R' || s[i][0] == 'C' || s[i][0] == 'H') {
           t[s[i][0]]++;
       }
   }

   ans += t['M'] * t['A'] * t['R'];
   ans += t['M'] * t['A'] * t['C'];
   ans += t['M'] * t['A'] * t['H'];
   ans += t['M'] * t['R'] * t['C'];
   ans += t['M'] * t['R'] * t['H'];
   ans += t['M'] * t['C'] * t['H'];
   ans += t['A'] * t['R'] * t['C'];
   ans += t['A'] * t['R'] * t['H'];
   ans += t['A'] * t['C'] * t['H'];
   ans += t['R'] * t['C'] * t['H'];

   std::cout << ans << "\n";
}