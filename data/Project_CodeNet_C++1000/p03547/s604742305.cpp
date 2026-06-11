 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
     char x, y;
     cin >> x >> y;
     if(x > y)
        printf(">\n");
     else if(x == y)
        printf("=\n");
     else
        printf("<\n");
     return 0;
 }
