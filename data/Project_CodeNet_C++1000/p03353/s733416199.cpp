
// C++ program to print all possible
// substrings of a given string
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char str[100000000][6], ct[27];
int cr[27] = {0};


// Function to print all sub strings
int subString(string s, int n, int d)
{
    // Pick starting point in outer loop
    // and lengths of different strings for
    // a given starting point
    int c=0, k=0;
    string sr;
    char ar[5010];
    for (int i = 0; i < n; i++)
    {
        for (int len = 1; len <= d; len++)
        {


            sr = s.substr(i, len);
            strcpy(ar, sr.c_str());
            if(ar[0] == ct[0] || ar[0] == ct[1] || ar[0] == ct[2] || ar[0] == ct[3])
            {
                strcpy(str[c], ar);
                c++;
            }
         //   printf("%d   ", c);
            if (c == 100000000)
            {
           //     printf("  Here \n");
                break;
            }

        }
    }
    return c;
}

void sorting(int n)
{
    char min[5010];
    int a;

    for (int i = 0; i < n - 1; i++)
    {
        a = i;
        strcpy(min, str[i]);

        for (int j = i + 1; j < n; j++)
        {
            if( (strcmp(str[j], min)) < 0)
            {
                strcpy(min, str[j]);
                a = j;
            }
        }
        strcpy(str[a], str[i]);
        strcpy(str[i], min);
    }
}

// Driver program to test above function
int main()
{
    string s;
    cin >> s;
    int d, i, j, k=0, l, p;
    char sry[5010], ch;
    strcpy(sry, s.c_str());
    l = strlen(sry);
    for ( j=0; j<l; j++)
        cr[sry[j]-'a'+1]++;
    for (j=0; j<26; j++)
    {
        if(cr[j] >= 1)
        {
            ct[j] = j + 'a' - 1;
            k++;
        }
        else
            ct[j] = 'z' ;
    }
    int q, w;
    char temp;
    // statements to scan the number of items (n) and the string a[n].

    for (w = 1; w < 26; w++)
    {
        for (q = 0; q < 26 - w; q++)
        {
            if (ct[q] >= ct[q+1])
            {
                temp = ct[q];
                ct[q] = ct[q+1];
                ct[q+1] = temp;
            }
        }
    }

    scanf("%d", &d);
    i = subString(s,s.length(), d);

    sorting(i);

//   printf("Here1[]\n");
    k=0;

    for(j=0; ; j++)
    {
        if (strcmp(str[j], str[j+1]) != 0)
            k++;
        if(k==d)
            break;

    }
    //  printf("Here1\n");
    printf ("%s", str[j]);

    /*  for(p=0; p<i; p++)
          printf("%s\n", str[p]);
          */
    return 0;
}