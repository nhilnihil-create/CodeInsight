 #include <bits/stdc++.h>
 using namespace std;

 typedef long long int ll;
 typedef long long unsigned int ull;
 typedef long double ld;
 typedef vector<int> vr;
 typedef pair<int, int> pr;
 #define pb push_back
 #define ff first
 #define ss second
 #define INF 1999999999
 #define MODA 1000000007
 #define PI 3.1415926535897932384626433
 #define endl "\n"
 //cout << fixed << setprecision(2);


 int main()
 {
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     string s;
     cin >> s;
     int len = s.size();
     string yy = "";
     yy = s[0];
     yy += s[1];
     string mm = "";
     mm = s[2];
     mm += s[3];


     int y = stoi(yy);
     int m = stoi(mm);

     if((y > 12 || y == 0) && (m >= 1 && m <= 12)){
        cout << "YYMM" << endl;
        //1905
     }
     else if((y >= 1 && y <= 12)&& (m > 12 || m == 0)){
        cout << "MMYY" << endl;
     }
     else if((y >= 1 && y <= 12)&& ( m >= 1 && m <= 12)){
        cout << "AMBIGUOUS" << endl;
        //0112
     }
     else if((y >= 1 || y <= 12) || (y >= 1 || y <= 12)){
        cout << "NA" << endl;
        //1700
     }
     return 0;
 }
