#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

//https://atcoder.jp/contests/abc088/tasks/abc088_b

int main()
{
    std::ios::sync_with_stdio(false); // toggler av synkronisjon mellom c og c++ data streams. kan ikke blade de etter skrudd av
    std::cin.tie(NULL);               //gj;r at man ikke venter på cout og de can printe samtidig tror jeg

    //linjen er opp til 100. det er en linje p[ lengde hundre med hus p[ bare de nevte stedene]]

    int numberOfCards;
    std::cin >> numberOfCards;

    std::vector<int> vec(numberOfCards);
    for (int i = 0; i < numberOfCards; i++)
    {
        std::cin >> vec[i];
    }

    std::sort(vec.begin(), vec.end(), std::greater<int>());

    int total = 0;
    int mul = 1;
    for (int i = 0; i < numberOfCards; i++)
    {
        total = total + (mul * vec[i]);
        mul = mul * -1;
    }

    std::cout << total << "\n";
}